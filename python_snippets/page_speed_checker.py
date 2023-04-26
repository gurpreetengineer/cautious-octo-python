import requests
import json

API_KEY = 'YOUR_API_KEY'
WEBSITE_URL = 'https://www.example.com'

url = f'https://www.googleapis.com/pagespeedonline/v5/runPagespeed?url={WEBSITE_URL}&key={API_KEY}'

response = requests.get(url)

data = json.loads(response.text)

performance_score = data['lighthouseResult']['categories']['performance']['score']
accessibility_score = data['lighthouseResult']['categories']['accessibility']['score']
best_practices_score = data['lighthouseResult']['categories']['best-practices']['score']
seo_score = data['lighthouseResult']['categories']['seo']['score']

print(f'Performance score: {performance_score}')
print(f'Accessibility score: {accessibility_score}')
print(f'Best practices score: {best_practices_score}')
print(f'SEO score: {seo_score}')
