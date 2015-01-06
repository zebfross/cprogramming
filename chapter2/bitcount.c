/*
	x &= (x-1)

	In a twos-compliment numbering system, this deletes the right-most 1 bit.
	This is because subtracting 1 will flip all zero bits to one until flipping
	the first one bit to zero and then stopping. 
*/

int bitcount_slow(unsigned x) {
	int b;
	
	for(b = 0; x != 0; x >>= 1)
		if(x & 01)
			b++;
	
	return b;
}

int bitcount_fast(unsigned x) {
	int b;

	for (b = 0; x != 0; x &= (x - 1))
		++b;
	
	return b;
}

int main() {
	return 0;
}

