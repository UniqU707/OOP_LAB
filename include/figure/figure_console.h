#pragma once

#include "figure/figure.h"
#include <iostream>
#include <conio.h>
#include <cstdio>

namespace console {
	void text_menu();
	int get_key();
	figure::Figure create_figure();
}