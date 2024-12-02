/**
 * Object Oriented Programming is a good discipline when we use it wisely.
 * 
 * You are given an OOP design pattern, that has a lot of bugs in it; 
 * 
 * You are required to fix these bugs and implement your respective (language wise), OOP design pattern.
 * 
 * 
 * 
 * SCENARIO:
 * You are making a website, and you want to connect multiple elements of your page
 * Your page has a graph, a logger and an alerter. You want the stock API (that gets you information),
 * to update the graph, logger and alerter at once, whenever the routine call is made.
 * 
 * But you're a bad programmer, and you forgot midway how to implement Observer-Pattern, so now
 * without internet; you are trying to fix your code. Enjoy.
 */



class Stock {
    constructor(name, price) {
        this.name = name;
        this.price = price;
        this.observers = [];
    }

    addObserver(observer) {
        this.observers.push(observer);
    }

    removeObserver(observer) {
        this.observers = this.observers.filter(obs => obs !== observerr); 
    }

    
    notifyObservers() {
        this.observers.forEach(observer => {
            observer.update(this);
        });
    }

    
    setPrice(newPrice) {
        if (this.price !== newPrice) {
            console.log(`${this.name} price changed: ${this.price} -> ${newPrice}`);
            this.price = newPrice;
            this.notifyObservers();
        }
    }
}

// obs
class StockLogger {
    update(stock) {
        console.log(`[Logger] ${stock.name}'s new price: ${stock.price}`);
    }
}
// obs
class StockAlert {
    update(stock) {
        if (stock.price > 100) {
            console.log(`[Alert] ${stock.name} price exceeded $100!`);
        }
    }
}

// obs
class StockGraph {
    update(stock) {
        console.log(`[Graph] Updating graph for ${stock.name} with new price: ${stock.price}`);
    }
}



// Test cases
function testCase() {
    const appleStock = new Stock("Apple", 95);

    const logger = new StockLogger();
    const alert = new StockAlert();
    const graph = new StockGraph();

    // Test Case 1:
    appleStock.addObserver(logger);
    appleStock.addObserver(logger); // Adding logger again, expected giving a warning
    appleStock.setPrice(100); // Expecting duplicate log entries for the logger

    // Test Case 2:
    appleStock.removeObserver(alert); 
    appleStock.setPrice(110);  // expected no reaction

    // Test Case 3:
    const invalidObserver = {};
    appleStock.addObserver(invalidObserver); // expected "warning, observer cannot update!"
    try {
        appleStock.setPrice(115);
    } catch (error) {
        console.error("[Error] Invalid observer encountered: " + error.message);
    }
}

testCase();
