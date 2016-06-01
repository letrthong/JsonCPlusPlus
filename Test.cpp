#include <iostream>
#include <stdio.h>

#include <json-c/json.h>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	cout<<"Hello world!"<<endl;
	char * string = "{\"name\" : \"programming\"}";
	json_object * jobj = json_tokener_parse(string);
	enum json_type type = json_object_get_type(jobj);
	printf("type:  %d\n",type);
	switch (type) {
	case json_type_null: 
		printf("json_type_null\n");
		break;
	case json_type_boolean: 
		printf("json_type_boolea\n");
		break;
	case json_type_double: 
		printf("json_type_double\n");
		break;
	case json_type_int: 
		printf("json_type_int");
		break;
	case json_type_object: 
		printf("json_type_object\n");
		break;
	case json_type_array: 
		printf("json_type_array\n");
		break;
	case json_type_string: 
		printf("json_type_string\n");
		break;
	}
   
    printf("json=[%s]\n",string);
	json_object_object_foreach(jobj, key, val) {
		type = json_object_get_type(val);
		printf("type:  %d\n",type);
		switch (type) {
		case json_type_string: 
			printf("json_type_string\n");
			printf("value: %s\n", json_object_get_string(val));
			break;
		}
	}
	return 0;
}