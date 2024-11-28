
/**
 * In a distant, alien civilization on the planet Zai'thar, there exists an ancient manuscript known as
 * The Codex of Zai'thar. This manuscript contains the true history of their people, but the Codex has been 
 * locked away for centuries. The Sovereign Order, an oppressive ruling class, controls access to the Codex, 
 * and only those with permission can read or alter it.
 * 
 * Writers in this world are high priests or scholars who have the authority to modify all Codices, 
 * but they can only do so when no one else is accessing the codex, they are subjects of Yaldabaoth,
 * -- God of Deception.
 * 
 * Readers are rebels or historians who attempt to uncover the truth hidden in the Codex by reading it,
 * the rebels and historians are subjects of Abraxas; God of Changing & Difference.
 *
 * You are required to simulate the Events Occurring:
 * 
 * * Priest writes to Codex,
 * * 3 Rebels read it [1,2,3]
 * * Priest writes to Codex, summoning God of Deception, Yaldabaoth
 * * 3 rebels read it [4,5,6]
 * * A Priest then writes to the XAFARIAN Codex, INSTEAD of the Zai'tharian codex to summon Pleromic Yaldabaoth
 */


#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <condition_variable>

using namespace std;


class Semaphore {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int value; 

public:
    Semaphore(int init_value) : value(init_value) {}

    
    void wait() {
        unique_lock<mutex> lock(mtx);
        while (value <= 0) {
            cv.wait(lock); 
        }
        value--;  
    }

    // Signal method (increment the semaphore)
    void signal() {
        lock_guard<mutex> lock(mtx);
        ++value;  
        cv.notify_one(); 
    }
};

class ReaderWriter {
private:
    Semaphore readSemaphore;  
    Semaphore writeSemaphore; 
    int readersCount;                    
    string filename;     
    condition_variable cv; 

public:
    ReaderWriter(const std::string& file)
        : readSemaphore(1), writeSemaphore(1), readersCount(0), filename(file) {}

    
    void readerStart() {
        readSemaphore.wait(); 
        ++readersCount;  
        if (readersCount == 1) {
            writeSemaphore.wait();  
        }
        readSemaphore.signal();
    }

    
    void readerEnd() {
        --readersCount;  
        if (readersCount == 0) {
            writeSemaphore.signal()
        }
    }

    
    void writerStart() {
        writeSemaphore.wait(); 
    }

    
    void writerEnd() {
        writeSemaphore.signal(); 
    }

    
    void readFile(int readerId) {
        std::ifstream file(filename);
        std::string line;

        if (file.is_open()) {
            std::cout << "Rebel " << readerId << " is reading the Codex:\n";
            while (std::getline(file, line)) {
                std::cout << line << "\n";
            }
            file.close();
        } else {
            std::cerr << "Rebel " << readerId << ": Failed to open the Codex for reading.\n";
        }
    }

    // Write to file
    void wrteFile(int writerId, const std::string& content) {
        ofstream file(filename, std::ios::app);  

        if (file.is_open()) {
            std::cout << "Priest " << writerId << " has written to the Codex: " << content << "\n";
            file << content << "\n";
            file.close();
        } else {
            std::cerr << "Priest " << writerId << ": Failed to write to the Codex.\n";
        }
    }
};


void readerThread(ReaderWriter& rw, int readerId) {
    this_thread::sleep_for(chrono::milliseconds(100 * readerId));  

    cout << "Rebel " << readerId << " is attempting to access the Codex...\n";
    rw.readerStart();  

    rw.readFile(readerId); 

    rw.readerEnd();  
    cout << "Rebel " << readerId << " has finished reading.\n";
}

// Writer thread function
void writerThread(ReaderWriter& rw, int writerId, const std::string& content) {
    this_thread::sleep_for(chrono::milliseconds(200 * writerId));  
    cout << "Priest " << writerId << " is preparing to write to the Codex...\n";
    rw.writerStart();  

    rw.writeFile(writerId, content); 

    rw.writerEnd();  
    std::cout << "Priest " << writerId << " has finished writing.\n";
}

int main() {
    std::string filename = "zaitharianCodex.txt";  
    ReaderWriter rw(filename); 

    
    std::vector<std::thread> threads;

    threads.push_back(std::thread(writerThread, std::ref(rw), 1, "Zai'thar IS LEGION!"));

    // Rebels reading the Codex
    for (int i = 1; i < 3; ++i) {
        threads.push_back(std::thread(readerThread, std::ref(rw), i));
    }

    // Another Priest writes to the Codex
    threads.push_back(std::thread(writerThread, std::ref(rw), 2, "Lo Yaldabaoth! And they shan't know of our deception; for we are best in deceiving."));

    // More Rebels reading the Codex
    for (int i = 4; i < 6; ++i) {
        threads.push_back(std::thread(readerThread, std::ref(rw), i));
    }

    return 0;
}
