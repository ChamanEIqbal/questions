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
 * You were an Employee of Media Streaming Company, and were fired because you were sleeping at your job instead of coding;
 * They said, your code is of no use; because you're always bugging up the production code, and the
 * higher ups that review your code before integration are lazy and are closer to the Boss than you are.
 * 
 * You cannot do anything but fix the code; and launch a new platform called "Watchify",
 * 
 * You're now looking at your code again, wanting to fix it. Enjoy.
 */

abstract class Media {
    protected String title;
    protected String releaseDate;
    protected int totalViews;

    public Media(String title, String releaseDate, int totalViews) {
        this.title = title;
        this.releaseDate = releaseDate;
        this.totalViews = totalViews;
    }

    public void displayDetails();
}

class Documentary extends Media {
    private String topic;

    public Documentary(String title, String releaseDate, int totalViews, String topic) {
        super(title, releaseDate, totalViews);
        this.topic = topic;
    }

    public void displayDetails() {
        System.out.println("Documentary: " + title + ", Release Date: " + releaseDate +
                           ", Total Views: " + totalViews + ", Topic: " + topic);
    }
}

class Movie extends Media {
    private String genre;

    public Movie(String title, String releaseDate, int totalViews, String genre) {
        super(title, releaseDate, totalViews);
        this.genre = genre;
    }

    public void displayDetails() {
        System.out.println("Movie: " + title + ", Release Date: " + releaseDate +
                           ", Total Views: " + totalViews + ", Genre: " + genre);
    }
}

class ComedyShow extends Media {
    private String comedian;

    public ComedyShow(String title, String releaseDate, int totalViews, String comedian) {
        super(title, releaseDate, totalViews);
        this.comedian = comedian;
    }


    public void displayDetails() {
        System.out.println("Comedy Show: " + title + ", Release Date: " + releaseDate +
                           ", Total Views: " + totalViews + ", Comedian: " + comedian);
    }
}

class LateNightShow extends Media {
    private String host;

    public LateNightShow(String title, String releaseDate, int totalViews, String host) {
        super(title, releaseDate, totalViews)
        this.host = host;
    }


    public void displayDetails() {
        System.out.println("Late Night Show: " + title + ", Release Date: " + releaseDate +
                           ", Total Views: " + totalViews + ", Host: " + host);
    }
}

class MediaFactory {
    public static Media createMedia(String type, String title, String releaseDate, int totalViews, String extra) {
        switch (type) {
            case "Documentary":
                return new Documentary(title, releaseDate, totalViews, extra);
            case "Movie":
                return new Movie(title, releaseDate, totalViews, extra);
            case "ComedyShow":
                return new ComedyShow(title, releaseDate, totalViews, extra);
            default:
                return new LateNightShow(title, releaseDate, totalViews, extra)
        }
    }
}

public class Watchify {
    public static void main(String[] args) {

        // Test Case 0:
        Media newMedia = MediaFactory.create_media("Musical", "Joker II", "2024-06-03", 10000, "Musical Movie")
        // Expected Output: "not supported, media type!"


        // Test case 1:
        Media doc = MediaFactory.create_media("Documentary", "Planet Earth", "2022-05-01", 100000, "Nature");
        Media movie = MediaFactory.create_media("Movie", "Inception", "2010-07-16", 200000, "Sci-Fi");
        Media comedy = MediaFactory.create_media("ComedyShow", "Stand-Up Hour", "2023-02-20", 50000, "John Doe");
        Media lateNight = MediaFactory.create_media("LateNightShow", "Tonight Show", "2021-09-12", 150000, "Jane Smith");

        doc.displayDetails(); // expected details
        movie.displayDetails(); // expected details
        comedy.displayDetails(); // expected details
        lateNight.displayDetails() // expected details

    }
}
