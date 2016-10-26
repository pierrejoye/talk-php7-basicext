<?php
if (!extension_loaded('myext')) {
	function myext_hello()
	{
		echo "Hello Manila!\n";
	}


	function myext_print(string $mystring)
	{
		echo "Hello " . $mystring . "!\n";
	}

	function myext_print_integer(int $myint)
	{
		if ($myint > 0) {
			for ($i = 0; $i < $myint; $i++) {
				echo "Hello " . $i . "!\n";
			}
		}
	}

	function myext_print_array(array $myarray) {
		foreach ($myarray as $val) {
			echo "hello ". $val . "\n";
		}
	}
} else {
	echo "my awesome extension is used!\n";
}
myext_hello();
myext_print("PHPPH");
myext_print_integer(3);
myext_print_array(['Jo', 'doh', 'Mr.']);