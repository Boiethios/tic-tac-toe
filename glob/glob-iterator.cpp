#include "glob-iterator.hpp"

dir_iterator_pattern::dir_iterator_pattern() :
	flags{ 0 },
	return_value{ GLOB_NOMATCH }
{
}

dir_iterator_pattern::dir_iterator_pattern(std::string pattern, int flags) :
	pattern{ pattern },
	flags{ flags },
	return_value{ GLOB_NOMATCH }
{
}

dir_iterator_pattern::dir_iterator_pattern(dir_iterator_pattern && that) :
	pattern{ that.pattern },
	flags{ that.flags },
	glob_infos{ that.glob_infos },
	return_value{ that.return_value },
	current_entry{ that.current_entry },
	index{ that.index }
{
	that.return_value = GLOB_NOMATCH;
	that.current_entry = fs::directory_entry{};
}

dir_iterator_pattern::~dir_iterator_pattern()
{
	if (not return_value)
	{
		globfree(&glob_infos);
	}
}

dir_iterator_pattern & dir_iterator_pattern::operator++()
{
	if (index < glob_infos.gl_pathc)
	{
		current_entry = fs::directory_entry{ glob_infos.gl_pathv[index] };
		++index;
	}
	else
	{
		current_entry = fs::directory_entry{};
	}
	return *this;
}

fs::directory_entry const & dir_iterator_pattern::operator*() const
{
	return current_entry;
}

bool dir_iterator_pattern::operator!=(dir_iterator_pattern const & that) const
{
	return **this != *that;
}


dir_iterator_pattern begin(dir_iterator_pattern const & that)
{
	dir_iterator_pattern ans{
		that.pattern, that.flags
	};

	ans.return_value = glob(ans.pattern.c_str(), ans.flags, nullptr, &ans.glob_infos);
	ans.index = 0u;
	++ans;
	return std::move(ans);
}

dir_iterator_pattern end(dir_iterator_pattern const &)
{
	return std::move(dir_iterator_pattern{});
}


