import re
htmlFile = open('links.html', 'r')
"\".*\""
for line in htmlFile:
    match1 = re.search('(".*")', line)
    if match1:
        match2 = re.sub('CLICKME', match1.group(1), line)
        print(match2)
