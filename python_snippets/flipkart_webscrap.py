import requests
from bs4 import BeautifulSoup

url = "https://www.flipkart.com/search?q=product"

# Change "product" in the above URL to the product you want to search for

response = requests.get(url)
soup = BeautifulSoup(response.content, "html.parser")

for product in soup.find_all("div", {"class": "_2kHMtA"}):
    # Change "_2kHMtA" to the appropriate class for the product you're searching for
    name = product.find("div", {"class": "_4rR01T"}).text.strip()
    price = product.find("div", {"class": "_30jeq3 _1_WHN1"}).text.strip()
    rating = product.find("div", {"class": "_3LWZlK"}).text.strip()

    print(name)
    print(price)
    print(rating)
    print()
