#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct material
{
	int protein, fat, carbohydrate, vitamin, price;

	material() : protein(0), fat(0), carbohydrate(0), vitamin(0), price(0) {}
	material(int _protein, int _fat, int _carbohydrate, int _vitamin, int _price) : 
	protein(_protein), fat(_fat), carbohydrate(_carbohydrate), vitamin(_vitamin), price(_price) {}

	void operator+=(const material &T)
	{
		protein += T.protein;
		fat += T.fat;
		carbohydrate += T.carbohydrate;
		vitamin += T.vitamin;
		price += T.price;
	}
	void operator-=(const material &T)
	{
		protein -= T.protein;
		fat -= T.fat;
		carbohydrate -= T.carbohydrate;
		vitamin -= T.vitamin;
		price -= T.price;
	}
};

const int MAX = 15;

int N, answer = INT_MAX;
material A[MAX], B, C;
bool visited[MAX];
vector<int> v, w;

void find_cost(int depth, int i, material T);
bool is_possible(material &T);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N;

	cin >> C.protein >> C.fat >> C.carbohydrate >> C.vitamin;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].protein >> A[i].fat >> A[i].carbohydrate >> A[i].vitamin >> A[i].price;
		B += A[i];
	}

	if (B.protein < C.protein || B.fat < C.fat || B.carbohydrate < C.carbohydrate || B.vitamin < C.vitamin)
	{
		cout << -1 << "\n";
		return 0;
	}
	
	find_cost(0, 0, material(0, 0, 0, 0, 0));

	if (answer != INT_MAX)
	{
		cout << answer << "\n";
		for(vector<int>::iterator i = w.begin(); i != w.end(); i++)
			cout << (*i) << " ";
		cout << "\n";
	}

	return 0;
}

void find_cost(int depth, int index, material T)
{
	if (T.price > answer)
		return;
	if (is_possible(T))
	{
		if (T.price < answer)
		{
			answer = T.price;
			w.assign(v.begin(), v.end());
		}
		return;
	}
	if (depth == N)
		return;
	for (int i = index; i < N; i++)
	{
		if (visited[i]) continue;

		visited[i] = true;
		T += A[i];
		v.push_back(i + 1);
		find_cost(depth + 1, i, T);
		visited[i] = false;
		T -= A[i];
		v.pop_back();
	}
}

bool is_possible(material &T)
{
	if (T.protein >= C.protein && T.fat >= C.fat && 
		T.carbohydrate >= C.carbohydrate && T.vitamin >= C.vitamin)
		return true;
	return false;
}
