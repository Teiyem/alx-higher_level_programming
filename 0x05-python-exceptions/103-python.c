#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints the size of the bytes object, the string representation
 * of the bytes object, and the first 10 bytes of the bytes object
 * @p: Pointer to the Python object
 * Return: void
 */
void print_python_bytes(PyObject *p)
{
	char *str;
	long int size;
	long int i;
	long int limit;

	setbuf(stdout, NULL);

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		setbuf(stdout, NULL);
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	str = ((PyBytesObject *)p)->ob_sval;

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);

	if (size >= 10)
		limit = 10;
	else
		limit = size + 1;

	printf("  first %ld bytes:", limit);

	for (i = 0; i < limit; i++)
		if (str[i] >= 0)
			printf(" %02x", str[i]);
		else
			printf(" %02x", 256 + str[i]);

	printf("\n");
	setbuf(stdout, NULL);
}

/**
 * print_python_float - Prints the value of a Python float object
 * @p: Pointer to the Python object
 * Return: void
 */
void print_python_float(PyObject *p)
{
	double val;
	char *nf;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");

	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		setbuf(stdout, NULL);
		return;
	}

	val = ((PyFloatObject *)(p))->ob_fval;
	nf = PyOS_double_to_string(val, 'r', 0, Py_DTSF_ADD_DOT_0, Py_DTST_FINITE);

	printf("  value: %s\n", nf);
	setbuf(stdout, NULL);
}

/**
 * print_python_list - Prints the size of the list,
 * the size of the allocated memory for the list, and the type of each element in the list
 * @p: Pointer to a Python object
 * Return: void
 */
void print_python_list(PyObject *p)
{
	long int size;
	long int i;
	PyListObject *list;
	PyObject *obj;

	setbuf(stdout, NULL);
	printf("[*] Python list info\n");

	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		setbuf(stdout, NULL);
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	list = (PyListObject *)p;

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < size; i++)
	{
		obj = list->ob_item[i];
		printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);

		if (PyBytes_Check(obj))
			print_python_bytes(obj);
		if (PyFloat_Check(obj))
			print_python_float(obj);
	}
	setbuf(stdout, NULL);
}
