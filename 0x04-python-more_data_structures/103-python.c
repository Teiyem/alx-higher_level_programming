#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

/**
 * print_python_bytes - prints the size of the bytes object,
 * the string representation of the bytes object, and the first
 * 10 bytes of the bytes object
 * @p: Pointer to the Python object
 * Return: void
 */
void print_python_bytes(PyObject *p)
{
	long int size;
	int i;
	char *str = NULL;

	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &str, &size);
	printf("  size: %li\n", size);
	printf("  trying string: %s\n", str);

	if (size < 10)
		printf("  first %li bytes:", size + 1);
	else
		printf("  first 10 bytes:");

	for (i = 0; i <= size && i < 10; i++)
		printf(" %02hhx", str[i]);

	printf("\n");
}

/**
 * print_python_list - Prints the size of the list, the size of
 * the allocated memory for the list, and the type of each element
 * in the list
 * @p: Pointer to a Python object
 * Return: void
 */
void print_python_list(PyObject *p)
{
	long int size = PyList_Size(p);
	int i;
	PyListObject *list = (PyListObject *)p;
	const char *tp_name;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %li\n", size);
	printf("[*] Allocated = %li\n", list->allocated);

	for (i = 0; i < size; i++)
	{
		tp_name = (list->ob_item[i])->ob_type->tp_name;

		printf("Element %i: %s\n", i, tp_name);

		if (!strcmp(tp_name, "bytes"))
			print_python_bytes(list->ob_item[i]);
	}
}
