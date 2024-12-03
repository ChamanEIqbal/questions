/*
Your task is to implement concurrency within the code:

using Promise API, and/or Mutex
*/
class Observable {
    constructor() {
        this.value = 0;
        this.observers = [];
    }

   
    addObserver(observer) {
        this.observers.push(observer);
    }

   
    removeObserver(observer) {
        const index = this.observers.indexOf(observer);
        if (index !== -1) {
            this.observers.splice(index, 1);
        }
    }

  
    notifyObservers() {
        this.observers.forEach(observer => {
            observer.update(this.value);
        });
    }

  
    updateValue(amount) {
        console.log(`Current value: ${this.value}`);
        this.value += amount; 
        this.notifyObservers();
    }
}

// Observer Class
class Observer {
    constructor(name) {
        this.name = name;
    }

    update(value) {
        console.log(`${this.name} received value update: ${value}`);
    }
}


function simulateConcurrency() {
    const observable = new Observable();


    const observer1 = new Observer("Observer 1");
    const observer2 = new Observer("Observer 2");


    observable.addObserver(observer1);
    observable.addObserver(observer2);


    setTimeout(() => {
        observable.updateValue(10); 
    }, 100);

    setTimeout(() => {
        observable.updateValue(20); 
    }, 200);

    setTimeout(() => {
        observable.updateValue(30); 
    }, 150);
}

simulateConcurrency();
