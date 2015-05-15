// HTMLTable.cpp

/************************************
*	Student: Anderson Fernandes		*
*	Class: ITSE 2421				*
*	Professor: Doug Edwards			*
*	Date: 4/5/2014					*
*	Assignment: Program 4			*
*************************************/

// This file defines all the functions of the HTMLTable class.
// This class writes a Bootstrap HTML 5 table

#include "HTMLTable.h"

void HTMLTable::writeRow(ostream &out, string tag, vector<string> row)
{
	out << "<tr>\n";
	for (unsigned int k = 0; k < row.size(); k++)
	{
		out << "<" << tag << "> "
			<< row[k] << " </" << tag << "> ";
	}
	out << "\n</tr>\n";
}

ostream & operator<<(ostream &out, HTMLTable htmlTable)
{
	// The following lines will write Bootstrap's HTML header
	out << "<!DOCTYPE html>";
	out << "<html lang=\"en\">";
	out << "<head>";
	out << "<meta charset=\"utf-8\">";
	out <<	"<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">";
	out <<	"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
	out <<	"<title>Cow Town College Alumini Program</title>";
	out <<	"";
	out <<	"	<!-- Bootstrap -->";
	out <<	"	<link href=\"bootstrap/css/bootstrap.min.css\" rel=\"stylesheet\">";
	out <<	"";
	out <<	"	<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->";
	out <<	"	<!--[if lt IE 9]>";
	out <<	"	  <script src=\"https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js\"></script>";
	out <<	"	  <script src=\"https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js\"></script>";
	out <<	"	<![endif]-->";
	out <<	" </head>";
	out <<	" <body>";
	
	out << "<table class=\"table table-striped table-hover\">\n";
	string sTitleTag;
	sTitleTag = "th colspan=\""
		+ to_string(htmlTable.headers.size())
			+ "\"style=\"text-align:center;font-size:40px\"\n";
	htmlTable.writeRow(out, sTitleTag.c_str(), htmlTable.title);

	htmlTable.writeRow(out, "th", htmlTable.headers);

	for (unsigned int r = 0; r < htmlTable.rows.size(); r++)
	{
		htmlTable.writeRow(out, "td", htmlTable.rows[r]);
	}
	out << "</table>\n";

	// The following lines will write Bootstrap's HTML footer
	out <<	"		<!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->";
    out <<	"		<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js\"></script>";
    out <<	"		<!-- Include all compiled plugins (below), or include individual files as needed -->";
    out <<	"		<script src=\"bootstrap/js/bootstrap.min.js\"></script>";
	out <<	"	</body>";
	out << "</html>";

	return out;
}
