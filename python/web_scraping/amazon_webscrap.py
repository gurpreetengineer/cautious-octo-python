import requests
from bs4 import BeautifulSoup

# Make a request to the Amazon website
url = 'https://www.amazon.com/'
response = requests.get(url)

# Parse the HTML content using BeautifulSoup
soup = BeautifulSoup(response.content, 'html.parser')

# Find all the links on the page
links = soup.find_all('a')

# Print the text of each link
for link in links:
    print(link.text)
