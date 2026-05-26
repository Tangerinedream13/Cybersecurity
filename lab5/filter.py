import sys

def process(line):
	ret = ""
	for c in line:
		if c == '“' or c == '”':
			ret = ret + '"'
		elif c == '’' or c =='‘':
			ret = ret + "'"
		else:
			ordy = ord(c)
			if ordy == 10 or (ordy >= 32 and ordy <= 126):
				ret = ret + c
	return ret

def filter(infile, outfile):
	with open(infile, "r") as inf, open(outfile, "w") as outf:
		for line in inf:
			line = process(line)
			outf.write(line)

argc = len(sys.argv)
if argc != 2 and argc != 3:
	print(f"Usage:")
	print(f"   {sys.argv[0]} filename - filter filename into filename.f")
	print(f"   {sys.argv[0]} filename1 filename2 - filter filename into filename2")
	exit(0)

in_file = sys.argv[1]
out_file = in_file + "f"
if argc == 3:
	out_file = sys.argv[2]
filter(in_file, out_file)
