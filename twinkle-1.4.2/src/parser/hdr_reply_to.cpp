/*
    Copyright (C) 2005-2009  Michel de Boer <michel@twinklephone.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "hdr_reply_to.h"
#include "definitions.h"

t_hdr_reply_to::t_hdr_reply_to() : t_header("Reply-To") {}

void t_hdr_reply_to::set_display(const string &d) {
	populated = true;
	display = d;
}

void t_hdr_reply_to::set_uri(const string &u) {
	populated = true;
	uri.set_url(u);
}

void t_hdr_reply_to::set_uri(const t_url &u) {
	populated = true;
	uri = u;
}

void t_hdr_reply_to::set_params(const list<t_parameter> &l) {
	populated = true;
	params = l;
}

void t_hdr_reply_to::add_param(const t_parameter &p) {
	populated = true;
	params.push_back(p);
}

string t_hdr_reply_to::encode_value(void) const {
	string s;

	if (!populated) return s;

	if (display.size() > 0) {
		s += '"';
		s += display;
		s += '"';
		s += ' ';
	}

	s += '<';
	s += uri.encode();
	s += '>';

	s += param_list2str(params);

	return s;
}
