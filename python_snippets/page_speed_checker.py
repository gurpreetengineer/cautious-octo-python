import requests
import json

API_KEY = 'YOUR_API_KEY_HERE'
WEBSITE_URL = 'https://www.google.com'

url = f'https://www.googleapis.com/pagespeedonline/v5/runPagespeed?url={WEBSITE_URL}&fields=lighthouseResult%2Fcategories%2F*%2Fscore&prettyPrint=false&strategy=desktop&category=performance&category=best-practices&category=accessibility&category=seo&key={API_KEY}'

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

# Refer this stackoverflow link
# https://stackoverflow.com/questions/53290705/find-score-inside-json-result-of-pagespeed-insights-api-v5

# Similar Output:
  
# Performance score: 0.99
# Accessibility score: 0.89
# Best practices score: 1
# SEO score: 0.82
