#include <iostream>
#include <stdio.h>

#include <json-c/json.h>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	cout<<"Hello world!"<<endl;
	char * string = "{\"Key\" : \"programming\"}";
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
			printf("key: %s\n", key);
			printf("value: %s\n", json_object_get_string(val));
			break;
		}
	}

	/*Creating a json object*/
    json_object * jobj1 = json_object_new_object();

    /*Creating a json string*/
    json_object *jstring = json_object_new_string("Joys of Programming");
    json_object_object_add(jobj1,"Site Name", jstring);

    printf ("The json object created: %s\n",json_object_to_json_string(jobj1));
    printf ("The json object created: \n%s\n", json_object_to_json_string_ext(jobj1,2));
	return 0;
}
