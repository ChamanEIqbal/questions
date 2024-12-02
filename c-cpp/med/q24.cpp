/**
 * Object Oriented Programming is a good discipline when we use it wisely.
 * 
 * You are given an OOP design pattern, that has a lot of bugs in it; 
 * 
 * You are required to fix these bugs and implement your respective (language wise), OOP design pattern.
 * 
 * 
 * SCENARIO:
 * You were an Employee of Media Streaming Company, and were fired because you were
 * sleeping at your job instead of coding;
 * They said, your code is of no use; because you're always bugging up the production code, and the
 * higher ups that review your code before integration are lazy and are closer to the Boss than you are.
 * 
 * You cannot do anything but fix the code; and launch a new platform called "Watchify",
 * 
 * You're now looking at your code again, wanting to fix it. Enjoy.
 */

#include <iostream>
#include <string>

using namespace std;

class Media {
    string title;
    string releaseDate;
    int totalViews;

public:
    Media(const string& title, const string& releaseDate, int totalViews)
        : title(title), releaseDate(releaseDate), totalViews(totalViews) {}

    virtual ~Media() {}

    void displayDetails() const = 0; 
};

// Derived classes
class Documentary : public Media {
    string topic;

public:
    Documentary(const string& title, const string& releaseDate, int totalViews, const string& topic)
        : Media(title, releaseDate, totalViews), topic(topic) {}
 
    void displayDetails() const  {
        cout << "Documentary: " << title << " | Release Date: " << releaseDate
             << " | Views: " << totalViews << " | Topic: " << topic << endl;
    }
};

class Movie : public Media {
    string genre;

public:
    Movie(const string& title, const string& releaseDate, int totalViews, const string& genre)
        : Media(title, releaseDate, totalViews), genre(genre) {}

    void displayDetails() const  {
        cout << "Movie: " << title << " | Release Date: " << releaseDate
             << " | Views: " << totalViews << " | Genre: " << genre << endl;
    }
};

class ComedyShow : public Media {
    string comedian;

public:
    ComedyShow(const string& title, const string& releaseDate, int totalViews, const string& comedian)
        : Media(title, releaseDate, totalViews), comedian(comedian) {}

    void displayDetails() const  {
        cout << "Comedy Show: " << title << " | Release Date: " << releaseDate
             << " | Views: " << totalViews << " | Comedian: " << comedian << endl;
    }
};

class LateNightShow : public Media {
    string host;

public:
    LateNightShow(const string& title, const string& releaseDate, int totalViews, const string& host)
        : Media(title, releaseDate, totalViews), host(host) {}

    void displayDetails() const  {
        cout << "Late Night Show: " << title << " | Release Date: " << releaseDate
             << " | Views: " << totalViews << " | Host: " << host << endl;
    }
};

// Factory class
class MediaFactory {
public:
    static Media* createMedia(const string& type, const string& title, const string& releaseDate,
                              int totalViews, const string& extra) {
        if (type == "Documentary")
            return new Documentary(title, releaseDate, totalViews, extra);
        else if (type == "Movie")
            return new Movie(title, releaseDate, totalViews, extra);
        else if (type == "ComedyShow")
            return new ComedyShow(title, releaseDate, totalViews, extra);
        else
            return new LateNightShow(title, releaseDate, totalViews, extra);

    }
};

int main() {

        // Test Case 0:
        Media* newMedia = createMedia("Musical", "Joke II", "2024-06-03", 10000, "Musical Movie");
        // Expected Output: "not a valid media type"

        // Test Case 1:
        Media* media1 =   createMedia("Documentary", "Planet Earth", "2006-03-05", 1000000, "Nature");
        Media* media2 =   createMedia("Movie", "Inception", "2010-07-16", 2000000, "Sci-Fi");

        media1->displayDetails(); // Expected details
        media2->displayDetails(); // Expected details

        delete media1;
        delete media2;

    return 0;
}
