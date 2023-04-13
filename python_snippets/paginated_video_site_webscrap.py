import requests
from bs4 import BeautifulSoup

for page in range(1, 101): # scrape up to 100 pages
    url = f"https://www.example.com/videos?page={page}"
    response = requests.get(url)

    soup = BeautifulSoup(response.content, "html.parser")

    videos = soup.find_all("div", {"class": "video"})

    for video in videos:
        title = video.find("h2").text.strip()
        duration = video.find("span", {"class": "duration"}).text.strip()
        views = video.find("span", {"class": "views"}).text.strip()

        print(f"Title: {title}")
        print(f"Duration: {duration}")
        print(f"Views: {views}")
        print()
