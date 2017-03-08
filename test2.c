#include <dlfcn.h>
#include <stdio.h>

void main(void)
{
	void *dlobj;
	void * (*init_appel)(char *name);
	void (*show_appel)(void *data);
	void (*destroy_appel)(char *data);

	if(dlobj=dlopen("libdobj.so.1", RTLD_LAZY))
	{
		void *data;

		init_appel=dlsym(dlobj,"init");
		show_appel=dlsym(dlobj,"montre");
		destroy_appel=dlsym(dlobj,"detruit");

		data=(*init_appel)("Test Objets");
		(*show_appel)(data);
		(*destroy_appel)(data);
	}
}