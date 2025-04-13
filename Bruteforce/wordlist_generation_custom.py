import re
import json

# Astrotalk terms, API components, names
base_terms = [
    "astrotalk", "astrologer", "panditji", "kirti", "vidhani", "KritiV", "Aayushi", 
    "Tarot", "Vedic", "consultant", "India", "INR", "device", "chat", "call",
    "Mac", "queue", "userId", "slug", "waitlist", "foreign", "training"
]

# Slug/skill identifiers from JSON
json_data = '''
{
    "skills": "10,1",
    "language": "1,2,21",
    "religionIds": "6,5",
    "userId": 1370064,
    "label": "1,2,3,4",
    "country": "91,1"
}
'''

terms_from_json = re.findall(r'"([^"]+)"', json_data)
all_words = set(base_terms + terms_from_json)

with open("wordlist.txt", "w") as f:
    for word in all_words:
        f.write(word.lower() + "\n")

print("✅ Wordlist generated: wordlist.txt")
