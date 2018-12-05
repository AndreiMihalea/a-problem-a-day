def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(f):
	return f(lambda x, y: x)

def cdr(f):
	return f(lambda x, y: y)

def main():
	print(car(cdr(cons(3, cons(4, 5)))))

if __name__ == "__main__":
	main()