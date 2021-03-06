/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe6.1.cpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <UnitTest++.h>
#include "shape_container.hpp"
#include "box.hpp"

using namespace std;


SUITE(container_testsuite)
{
	shape* shapePtr = new box();
	box* boxPtr = new box();
	shape_container cont;

	TEST(check_constructor_and_add)
	{
		cont.add(shapePtr);
		CHECK_EQUAL(cont.size(),1);
	}

	TEST(check_remove)
	{
		cont.remove(shapePtr);
		CHECK_EQUAL(cont.size(), 0);
	}
	
	TEST(check_find) {
		cont.add(boxPtr);
		cont.remove(cont.find("tube"));
		CHECK_EQUAL(cont.size(), 1);
		cont.remove(cont.find("box"));
		CHECK_EQUAL(cont.size(), 0);
	}
}

int main()
{
	return UnitTest::RunAllTests();
}
