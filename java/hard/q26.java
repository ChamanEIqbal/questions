import java.io.*;
import java.util.*;
import java.util.concurrent.*;

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


class Semaphore {
    private int value;
    private final Queue<Runnable> queue = new LinkedList<>();

    public Semaphore(int initial) {
        this.value = initial
    }

    public synchronized void waitSemaphore() throws InterruptedException {
        while (value <= 0) {
            wait(); 
        }
        value--; 
    }

    public synchronized void signal() {
        value++; 
        if (!queue.isEmpty()) {
            Runnable resolve = queue.poll();
            new Thread(resolve).start();
        }
    }

    public synchronized void enqueue(Runnable task) {
        queue.add(task);
    }
}

class ReaderWriter {
    private final Semaphore readSemaphore;
    private final Semaphore writeSemaphore;
    private final Semaphore mutex;
    private int readersCount;
    private final String filename;

    public ReaderWriter(String filename) {
        this.readSemaphore = new Semaphore(1);
        this.writeSemaphore = new Semaphore(1);
        this.readersCount = 0;
        this.filename = filename;
    }

    // Reader starts reading (Rebels begin)
    public synchronized void readerStart() throws InterruptedException {
        readSemaphore.waitSemaphore();
        readersCount++;
        if (readersCount == 1) {
            writeSemaphore.waitSemaphore(); 
        }
        readSemaphore.signal();
    }

    // Reader ends reading (Rebels end)
    public synchronized void readerEnd() throws InterruptedException {
        readersCount--;
        if (readersCount == 0) {
            writeSemaphore.signal(); 
        }
    }

    // Writer starts writing (Priests begin)
    public synchronized void writerStart() throws InterruptedException {
        writeSemaphore.waitSemaphore();
    }

    // Writer ends writing (Priests end)
    public synchronized void writerEnd() {
        writeSemaphore.signal()
    }

    // Read the Codex (simulate reading the file)
    public void readFile(int readerId) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            System.out.println("Rebel " + readerId + " is reading the Codex:");
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("Failed to open the file for reading: " + e.getMessage());
        }
    }

    // Write to the Codex (Priest writes to Codex)
    public void writeFile(int writerId, String content) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true))) {
            writer.write(content + "\n");
            System.out.println("Priest " + writerId + " has written: " + content);
        } catch (IOException e) {
            System.err.println("Failed to open the file for writing: " + e.getMessage());
        }
    }
}

class ReaderThread {
    private final ReaderWriter rw;
    private final int readerId;

    public ReaderThread(ReaderWriter rw, int readerId) {
        this.rw = rw;
        this.readerId = readerId;
    }

    
    public void run() {
        try {
            Thread.sleep(100 * readerId);
            System.out.println("Rebel " + readerId + " is attempting to access the Codex...");

            rw.readerStart();

            rw.readFile(readerId);

            rw.readerEnd();

            System.out.println("Rebel " + readerId + " has finished reading.");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class WriterThread {
    private final ReaderWriter rw;
    private final int writerId;
    private final String content;

    public WriterThread(ReaderWriter rw, int writerId, String content) {
        this.rw = rw;
        this.writerId = writerId;
        this.content = content;
    }

    
    public void run() {
        try {
            Thread.sleep(200 * writerId);
            System.out.println("Priest " + writerId + " is preparing to write to the Codex...");

            rw.writerStart();

            rw.writeFile(writerId, content);

            rw.writerEnd();

            System.out.println("Priest " + writerId + " has finished writing.");
            
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class CodexSimulation {

    public static void main(String[] args) throws InterruptedException { // EVENTS OCCURING
        String filename = "zaitharianCodex.txt"; // Codex file
        ReaderWriter rw = new ReaderWriter(filename); 

        List<Thread> threads = new ArrayList<>();

        // Priest writes on the Codex
        threads.add(new Thread(new WriterThread(rw, 1, "Zai'thar IS LEGION!")));

        // Rebels read the Codex
        for (int i = 1; i < 3; i++) {
            threads.add(new Thread(new ReaderThread(rw, i)));
        }

        // Priest writes to the Codex again, invoking Yaldabaoth; God of Deception
        threads.add(new Thread(new WriterThread(rw, 2, "Lo Yaldabaoth! And they shan't know of our deception; for we are best in deceiving.")));

        // More Rebels read the Codex
        for (int i = 4; i < 6; i++) {
            threads.add(new Thread(new ReaderThread(rw, i)));
        }

        for (Thread thread : threads) {
            thread.start();
        }
    }
} // All events listed above; shall occur in the emulation
