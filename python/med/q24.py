"""
 # Object Oriented Programming is a good discipline when we use it wisely.
 # 
 # You are given an OOP design pattern, that has a lot of bugs in it; 
 # 
 # You are required to fix these bugs and implement your respective (language wise), OOP design pattern.
 # 
 # 
 # 
 # SCENARIO:
 # You were an Employee of Media Streaming Company, and were fired because you were sleeping at your job instead of coding;
 # They said, your code is of no use; because you're always bugging up the production code, and the
 # higher ups that review your code before integration are lazy and are closer to the Boss than you are.
 # 
 # You cannot do anything but fix the code; and launch a new platform called "Watchify",
 # 
 # You're now looking at your code again, wanting to fix it. Enjoy.
 """

from abc import ABC, abstractmethod # abstract classes and methods


class Media():
    def __init__(self, title, release_date, total_views):
        self.title = title
        self.release_date = release_date
        self.total_views = total_views

    @abstractmethod
    def display_details(self):
        pass


class Documentary(Media):
    def __init__(self, title, release_date, total_views, topic):
        super().__init__(title, release_date, total_views)
        self.topic = topic

    def display_details(self):
        print(
            f"Documentary: {self.title}, Release Date: {self.release_date}, "
            f"Total Views: {self.total_views}, Topic: {self.topic}"
        )


class Movie(Media):
    def __init__(self, title, release_date, total_views, genre):
        super().__init__(title, release_date, total_views)
        self.genre = genre

    def display_details(self):
        print(
            f"Movie: {self.title}, Release Date: {self.release_date}, "
            f"Total Views: {self.total_views}, Genre: {self.genre}"
        )


class ComedyShow(Media):
    def __init__(self, title, release_date, total_views, comedian):
        super().__init__(title, release_date, total_views)
        self.comedian = comedian

    def display_details(self):
        print(
            f"Comedy Show: {self.title}, Release Date: {self.release_date}, "
            f"Total Views: {self.total_views}, Comedian: {self.comedian}"
        )


class LateNightShow(Media):
    def __init__(self, title, release_date, total_views, host):
        super().__init__(title, release_date, total_views)
        self.host = host

    def display_details(self):
        print(
            f"Late Night Show: {self.title}, Release Date: {self.release_date}, "
            f"Total Views: {self.total_views}, Host: {self.host}"
        )


class MediaFactory:
    @staticmethod
    def create_media(media_type, title, release_date, total_views, extra):
        if media_type == "Documentary":
            return Documentary(title, release_date, total_views, extra)
        elif media_type == "Movie":
            return Movie(title, release_date, total_views, extra)
        elif media_type == "ComedyShow":
            return ComedyShow(title, release_date, total_views, extra)
        else:
            return LateNightShow(title, release_date, total_views, extra)


if __name__ == "__main__":


    # Test Case 0:
    newMedia = MediaFactory.create_media("Musical", "Joker II", "2024-07-01", 100000, "Musical Movie") 
    # Expected Output: Not a Media Type!

    # Test Case 1:
    doc = MediaFactory.create_media("Documentary", "Planet Earth", "2022-05-01", 100000, "Nature")
    movie = MediaFactory.create_media("Movie", "Inception", "2010-07-16", 200000, "Sci-Fi")
    comedy = MediaFactory.create_media("ComedyShow", "Stand-Up Hour", "2023-02-20", 50000, "John Doe")
    late_night = MediaFactory.create_media("LateNightShow", "Tonight Show", "2021-09-12", 150000, "Jane Smith")

    doc.display_details() # Expected Details
    movie.display_details() # Expected Details
    comedy.display_details() # Expected Details
    late_night.display_details() # Expected Details

    
