import requests
from bs4 import BeautifulSoup
import smtplib

# Set up SMTP server
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login('youremail@gmail.com', 'yourpassword')

# Get content for newsletter
url = 'https://www.example.com'
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')
content = soup.find_all('div', class_='content')

# Create email
from_email = 'youremail@gmail.com'
to_email = 'recipientemail@gmail.com'
subject = 'Newsletter for the week'
body = f"""
Dear Subscriber,

Here's your weekly newsletter with the latest content from our website:

{content}

Best,
Your Name
"""
message = f'Subject: {subject}\n\n{body}'

# Send email
server.sendmail(from_email, to_email, message)

# Close connection
server.quit()
