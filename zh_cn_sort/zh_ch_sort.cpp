#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <algorithm>

using namespace std;

/*
Linux g++ locale ����: "zh_CN.utf"
 VC2010 locale ���ƣ�    "Chinese"����"Chinese_china"
*/
#ifdef _MSC_VER
    static const char *ZH_CN_LOCALE_STRING = "Chinese_china";
#else
    static const char *ZH_CN_LOCALE_STRING = "zh_CN.utf8";
#endif

static const locale zh_CN_locale = locale(ZH_CN_LOCALE_STRING);
static const collate<char>& zh_CN_collate = use_facet<collate<char> >(zh_CN_locale);

bool zh_CN_less_than(const string &s1, const string &s2){
	const char *pb1 = s1.data();
	const char *pb2 = s2.data();
	return (zh_CN_collate.compare(pb1, pb1 + s1.size(), pb2, pb2 + s2.size()) < 0);
}

int main(void)
{
	vector<string> v;
	v.push_back("��");
	v.push_back("��");
	v.push_back("��һ");
	v.push_back("�ڶ�");
	v.push_back("�ڷ�");
	v.push_back("di");
	v.push_back("����");
	v.push_back("liu");
	v.push_back("����");
	v.push_back("����");
	v.push_back("abc");
	v.push_back("aa");

        cout << "locale name: " << zh_CN_locale.name() << endl;
	sort(v.begin(), v.end(), zh_CN_less_than);
	for (vector<string>::const_iterator p = v.begin(); p != v.end(); ++p){
		cout << *p << endl;
	}
	return EXIT_SUCCESS;
}
