"""
/##
 # In a distant, alien civilization on the planet Zai'thar, there exists an ancient manuscript known as
 # The Codex of Zai'thar. This manuscript contains the true history of their people, but the Codex has been 
 # locked away for centuries. The Sovereign Order, an oppressive ruling class, controls access to the Codex, 
 # and only those with permission can read or alter it.
 # 
 # Writers in this world are high priests or scholars who have the authority to modify all Codices, 
 # but they can only do so when no one else is accessing the codex, they are subjects of Yaldabaoth,
 # -- God of Deception.
 # 
 # Readers are rebels or historians who attempt to uncover the truth hidden in the Codex by reading it,
 # the rebels and historians are subjects of Abraxas; God of Changing & Difference.
 #
 # You are required to simulate the Events Occurring:
 # 
 # # Priest writes to Codex,
 # # 3 Rebels read it [1,2,3]
 # # Priest writes to Codex, summoning God of Deception, Yaldabaoth
 # # 3 rebels read it [4,5,6]
 # # A Priest then writes to the XAFARIAN Codex, INSTEAD of the Zai'tharian codex to summon Pleromic Yaldabaoth
 #/
"""

import time
import threading

class Semaphore:
    def __init__(self, initial):
        self.value = initial
        self.queue = []

    def wait(self):
        if self.value > 0:
            self.value -= 1
        else:
            event = threading.Event()
            self.queue.append(event)
            event.wait()  

    def signal(self):
        if self.queue:
            event = self.queue.pop(0)
            event.set()  
        else:
            self.value += 1

class ReaderWriter:
    def __init__(self, filename):
        self.readSemaphore = Semaphore(1) 
        self.writeSemaphore = Semaphore(1) 
        self.readersCount = 0
        self.filename = filename

    def readerStart(self):
        self.readSemaphore.wait()

        self.readersCount += 1
        if self.readersCount == 1:
            self.writeSemaphore.wait() 

        self.readSemaphore.signal()

    def readerEnd(self):
        self.readersCount -= 1
        if self.readersCount == 0:
            self.writeSemaphore.signal()

    def writerStart(self):
        self.writeSemaphore.wait()  

    def writerEnd(self):
        self.writeSemaphore.signal()

    def readFile(self, readerId):
        try:
            with open(self.filename, 'r') as file:
                print(f"Rebel {readerId} is reading the Codex:")
                print(file.read()) 
        except FileNotFoundError:
            print(f"Rebel {readerId}: Failed to open the Codex for reading.")

    def writeFile(self, writerId, content):
        try:
            with open(self.filename, 'w') as file:  
                file.write(content + "\n")
            print(f"Priest {writerId} has written to the Codex: {content}")
        except Exception as e:
            print(f"Priest {writerId}: Failed to write to the Codex. Error: {str(e)}")

def readerThread(rw, readerId):
    time.sleep(0.1 * readerId)  
    print(f"Rebel {readerId} is attempting to access the Codex...")
    rw.readerStart()

    rw.readFile(readerId)

    rw.readerEnd()
    print(f"Rebel {readerId} has finished reading.")

def writerThread(rw, writerId, content):
    time.sleep(0.2 * writerId)  
    print(f"Priest {writerId} is preparing to write to the Codex...")
    rw.writerStart()

    rw.writeFile(writerId, content)

    rw.writerEnd()
    print(f"Priest {writerId} has finished writing.")

def main():
    filename = 'zaitharianCodex.txt' 
    rw = ReaderWriter(filename)

    threads = []

    
    threads.append(threading.Thread(target=writerThread, args=(rw, 1, "Zai'thar IS LEGION!")))

    # Rebels reading the Codex
    for i in range(1, 3):
        threads.append(threading.Thread(target=readerThread, args=(rw, i)))

    # Another priest writes to the Codex, calls upon Yaldabaoth
    threads.append(threading.Thread(target=writerThread, args=(rw, 2, "Lo Yaldabaoth! And they shan't know of our deception; for we are best in deceiving.")))

    # More rebels read the Codex
    for i in range(4, 6):
        threads.append(threading.Thread(target=readerThread, args=(rw, i)))

    for thread in threads:
        thread.start()


if __name__ == "__main__":
    main() # All events listed above; shall occur in the emulation
