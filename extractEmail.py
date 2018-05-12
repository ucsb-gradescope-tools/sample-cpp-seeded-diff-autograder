import json
import sys

if len(sys.argv) != 2:
	print("Incorrect number of command line parameters. Exiting...")
	exit()
else:
	print(sys.argv[1])

with open('/autograder/submission_metadata.json') as json_data:
	d = json.load(json_data)
	email = d[u'users'][0][u'email']
	print(email)
