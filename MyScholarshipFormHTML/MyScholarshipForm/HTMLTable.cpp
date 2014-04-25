#include "stdafx.h"
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
	out << "<table border = \"1\">\n";
	string sTitleTag;
	sTitleTag = "th colspan=\""
		+ to_string(htmlTable.headers.size())
			+ "\"\n";
	htmlTable.writeRow(out, sTitleTag.c_str(), htmlTable.title);

	htmlTable.writeRow(out, "th", htmlTable.headers);

	for (unsigned int r = 0; r < htmlTable.rows.size(); r++)
	{
		htmlTable.writeRow(out, "td", htmlTable.rows[r]);
	}
	out << "</table>\n";
	return out;
}