#!/usr/bin/env python3

import json
import sys
import argparse
import textwrap

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='extract email from gradescope metadata',
        formatter_class=argparse.RawTextHelpFormatter)

    parser.add_argument('jsonfile', default="/autograder/submission_metadata.json",
        help= textwrap.dedent('''\

        This file is typically /autograder/submission_metadata.json.  The name can be
        specified on the command line for testing purposes.
       '''))

    args = parser.parse_args()    


    with open(args.jsonfile) as json_data:
      d = json.load(json_data)
      email = d[u'users'][0][u'email']
      print(email)
