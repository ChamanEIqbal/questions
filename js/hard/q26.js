
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


const fs = require('fs').promises;

class Semaphore {
  constructor(initial) {
    this.value = initial; 
    this.queue = []; 
  }

  async wait() {
    if (this.value > 0) {
      this.value--; 
      return;
    }


    return new Promise(function(resolve) {
      this.queue.push(resolve);
    });
  }


  signal() {
    if (this.queue.length > 0) {
      const resolve = this.queue.shift(); 
      resolve();
    } else {
      this.value++; 
    }
  }
}

class ReaderWriter {
  constructor(filename) {
    this.readSemaphore = new Semaphore(1); 
    this.writeSemaphore = new Semaphore(1); 
    this.readersCount = 0; 
    this.filename = filename; 
    this.mutex = new Semaphore(1); 
  }

  
  async readerStart() { // the starting of the rebellion
    await this.readSemaphore.wait();
    await this.mutex.wait();

    this.readersCount++;
    if (this.readersCount === 1) {
      await this.writeSemaphore.wait(); 
    }

    this.mutex.signal();
    this.readSemaphore.signal();
  }

  
  async readerEnd() { // the ending of the rebellion
    await this.mutex.wait();

    this.readersCount--;
    if (this.readersCount === 0) {
      this.writeSemaphore.signal(); 
    }

    this.mutex.signal();
  }

  
  async writerStart() { // the misuse of the Codex by a Priest.
    await this.writeSemaphore.wait();
  }

  
  async writerEnd() { // Priest announces in the High Temple, that the codex has been changed.
    this.writeSemaphore.signal();
  }

  
  async readFile(readerId) {
    try {
      const data = await fs.readFile(this.filename, 'utf-8');
      console.log(`Reader ${readerId} is reading from the file:`);
      console.log(data);
    } catch (error) {
      console.error("Failed to open the file for reading:", error);
    }
  }

  async writeFile(writerId, content) {
    try {
      await fs.writeFile(this.filename, content + '\n');
      console.log(`Writer ${writerId} has written: ${content}`);
    } catch (error) {
      console.error("Failed to open the file for writing:", error);
    }
  }
}

async function readerThread(rw, readerId) {
  await new Promise(function(resolve) {setTimeout(resolve, 100 * readerId)}); 
  console.log(`Rebel ${readerId} is attempting to access the codex...`);
  await rw.readerStart();

  
  await rw.readFile(readerId);

  await rw.readerEnd();
  console.log(`Rebel ${readerId} has finished reading.`);
}

async function writerThread(rw, writerId, content) {
  await new Promise(resolve => setTimeout(resolve, 200 * writerId)); 
  console.log(`Priest ${writerId} is preparing to write to the file...`);
  await rw.writerStart(); 

  
  await rw.writeFile(writerId, content);

  await rw.writerEnd();
  console.log(`Priest ${writerId} has finished writing.`); 
}

async function main() {
  const filename = 'zaitharianCodex.txt'; 
  const rw = new ReaderWriter(filename); 
  
  const threads = [];

// High Priests write on the codex; to exalt Zai'thar's power and exploit it for their reign!
  threads.push(writerThread(rw, 1, "Zai'thar IS LEGION!"));

// Rebels expose the High Priests to the general residents of the Empire
  for (let i = 1; i < 3; i++) {
    threads.push(readerThread(rw, i));
  }
// High Priests are now summoning an ancient God of Deception through the codex
  threads.push(writerThread(rw, 2, "Lo Yaldabaoth! And they shan't know of our deception; for we are best in deceiving."));

// Rebels get to know of their plan beforehand and now intend to stop the High preists
  for (let i = 4; i < 6; i++) {
    threads.push(readerThread(rw, i));
  }
}

main();
