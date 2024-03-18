#include <iostream>
#include <vector>

struct Vector3
{
	int x, y, z;

	Vector3()
	{

	}
	Vector3(int x, int y, int z) : x(x), y(y), z(z)
	{

	}

	Vector3 operator + (const Vector3& v1); // хороший совет лучше реализацию оставлять ниже!!!
	/*{
		return Vector3(this->x + v1.x, this->y + v1.y, this->z + v1.z);
	}*/
	
	

	//void operator = (const Vector3& v1)
	//{
	//	this->x + v1.x, this->y + v1.y, this->z = 0;
	//}
	
	//Vector3 operator = (const Vector3& v1)
	//{
	//	if (&v1 == this) // Тут делаем проверку для того чтобы не создавать копию переменной. 
	//	{
	//		return *this;
	//		return Vector3(this->x = v1.x, this->y = v1.y, this->z = 0);
	//		// больше памяти но можно ставить скобки
	//	}
	//};

	friend Vector3 operator + (Vector3& v1, Vector3& v2);
	friend Vector3 operator - (Vector3& v1);
};

struct Vector2
{
	Vector2 operator + (Vector3 v3);

	friend Vector2 operator + (Vector3 v3, Vector2 v2);
};
//
//Vector3 Vector3::operator + (const Vector3& v1)
//{
//	return Vector3(this->x + v1.x, this->y + v1.y, this->z + v1.z);
//}


//Vector3 operator + (const Vector3& v1, Vector3& v2 )
//{
//	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
//}

int main()
{
	Vector3 v1(10, 10, 10);
	Vector3 v2(30, 30, 30);
	Vector3 v3;

	v3 = v1 + v2;
	v3 = v2;


	return 0;
}