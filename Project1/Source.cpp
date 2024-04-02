#include <iostream>
#define FILL_FACTOR 75

typedef struct
{
	std::string key;
	int value;
} Item;

typedef struct
{
	Item* elements;
	int capacity = 32;
	int cout;

	long hash(std::string key)
	{
		long sum = 0;
		for (int i = 0; i < key.length(); i++)
		{
			sum += key[i] * (i + 1);
		}
		return sum;

	}

	void realloc()
	{
		if (this->cout / this->capacity * 100 >= FILL_FACTOR)
		{
			this->elements = (Item*)std::realloc(NULL, this->capacity * 2);
			this->capacity *= 2;
		}
	}

	void init()
	{
		this->elements = (Item*)malloc(this->capacity * sizeof(Item));
	}

	void add(std::string key, int value)
	{
		realloc();
		long hashed = hash(key);
		if (this->elements[hashed].key != "")
		{
			long temp = hashed + 1;
			while (this->elements[temp].key != "")
			{
				temp++;
			}
			this->elements[temp].key = key;
			this->elements[temp].value = value;
		}
		else
		{
			this->elements[hashed].key = key;
			this->elements[hashed].value = value;
		}
			this->cout++;
	}

	int get(std::string key)
	{
		long hashed = hash(key);
		if (this->elements[hashed].key == key)
		{
			return this->elements[hashed].value;
		}
		else
		{
			for (int i = hashed +1; i < hashed + this->capacity; ++i)
			{
				if (i == hashed) break;
				if (this->elements[i].key == key) return this->elements[i].value;
			}
			return -1;
		}
	}

} Hashmap;

int main() 
{
	Hashmap hashmap;
	hashmap.init();
	hashmap.add("ten", 10);
	hashmap.add("elevem", 11);
	hashmap.add("lol", 32);
	hashmap.add("pikachu", 1);
	std::cout << hashmap.get("pikachu");
}