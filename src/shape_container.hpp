/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * shape_container.hpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <list>
#include <string>
#include "shape.hpp"

class shape_container
{
public:
	shape_container();
	shape_container(shape*);
	shape_container(shape_container const&);
	~shape_container();

	shape_container& operator=(shape_container const&);
	
	shape_container clone_deep() const;
	shape_container clone_shallow() const;
	void add(shape*);
	void remove(shape*);
	shape* find(std::string const&) const;
	int size() const;
	void print() const;
	double volume() const;

private:
	std::list<shape*> shapes_;
};
