#! python3
#Implementing a Google I'm Feeling Lucky Page

import requests, sys, webbrowser, bs4
'''
requests is for downloading web pages, sys is for using command line syntaxes, webbrowser is for gaining control over the browser and bs4 is for parsing throught the various html tags
'''
print ("Googling...")
res = requests.get('http://google.com/search?q=' + ' '.join(sys.argv[1:]))
'''
what we did here was to download the webpage we get on searching; we used argv to get the parameters after the first one since the first is always the name of the file
'''
res.raise_for_status()
elements = bs4.BeautifulSoup(res.text, "lxml")
linkElems = elements.select('.r a')
'''
a little investigation shows how .r is present in all search result tags
'''
numOpen= min(5, len(linkElems))
for i in range(numOpen):
    webbrowser.open('http://google.com' + linkElems[i].get('href'))
