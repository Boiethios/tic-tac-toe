#include <experimental/filesystem>

#include <glob.h>

namespace fs = std::experimental::filesystem;

class dir_iterator_pattern
{
	friend dir_iterator_pattern end(dir_iterator_pattern const &);
	friend dir_iterator_pattern begin(dir_iterator_pattern const &);

	std::string pattern;
	int flags;
	glob_t glob_infos;
	int return_value{ 0 };

	fs::directory_entry current_entry;
	std::size_t index;

	dir_iterator_pattern();

public:
	dir_iterator_pattern & operator=(dir_iterator_pattern const &) = delete;

	dir_iterator_pattern(std::string pattern, int flags = 0);
	dir_iterator_pattern(dir_iterator_pattern const &) = delete;
	dir_iterator_pattern(dir_iterator_pattern &&);
	~dir_iterator_pattern();

	dir_iterator_pattern & operator++();
	fs::directory_entry const & operator*() const;
	bool operator!=(dir_iterator_pattern const &) const;
};

//dir_iterator_pattern end(dir_iterator_pattern const &);
