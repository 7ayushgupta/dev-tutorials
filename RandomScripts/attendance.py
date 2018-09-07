import requests
r = requests.get('http://adarshaj.cse.iitk.ac.in/nyo/table.txt')
data = r.text
index = r.find('170191')
print index
