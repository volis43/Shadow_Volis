#include <iostream>
#include <string>
#define FILL_FACTOR 75



typedef struct Item
{
	std::string key;
	int value = 0;
}Item;


typedef struct Hashmap
{
	Item* elements = 0;
	int capacity = 32;
	int cout = 0;

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
		if (this->cout * 100 / this->capacity >= FILL_FACTOR)
		{
			this->elements = (Item*)std::realloc(this->elements, this->capacity * 2 * sizeof(Item));
			this->capacity *= 2;
		}
	}

	void init()
	{
		this->elements = (Item*)std::malloc(this->capacity * sizeof(Item));
	}

	void add(std::string key, int value)
	{
		realloc();
		long hashed = hash(key);
		if (this->elements[hashed].key != "")
		{
			long temp = (hashed + 1) % this->capacity;
			while (this->elements[temp].key != "")
			{
				temp = (temp + 1) % this->capacity;
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
			for (int i = 1; i < this->capacity; ++i)
			{
				int index = (hashed + 1) % this->capacity;
				if (this->elements[index].key == key) return this->elements[index].value;
			}
			return -1;
		}
		
~Hashmap()
		{

		}
	}

}Hashmap;

int main() 
{
	Hashmap hashmap;
	hashmap.init();
	hashmap.add("ten", 10);
	/*hashmap.add("elevem", 11);*/
	hashmap.add("lol", 3);
	hashmap.add("pikachu", 1);
	std::cout << hashmap.get("pikachu");
}