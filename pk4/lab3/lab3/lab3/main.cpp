#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

void zadanie2()
{
	fs::path sciezkaPoczatkowa("KatalogZadaniowy");
	fs::path sciezkaDocelowa("KatalogZadaniowy2");
	if (!fs::exists(sciezkaDocelowa))
	{
		fs::create_directory(sciezkaDocelowa);
	}
	for (const auto& it : fs::directory_iterator(sciezkaPoczatkowa))
	{
		fs::path sciezkaTymczasowa(it);
		fs::copy(it, sciezkaDocelowa / sciezkaTymczasowa.filename(), fs::copy_options::overwrite_existing);
	}
}

void zadanie3()
{
	fs::path nowaSciezka("KatalogZadaniowy2");
	if (fs::exists(nowaSciezka))
	{
		for (const auto& it : fs::directory_iterator(nowaSciezka))
		{
			fs::path sciezkaTymczasowa(it);
			std::cout <<"Sciezka do pliku " << sciezkaTymczasowa.filename() <<":\n" << fs::absolute(sciezkaTymczasowa) << "\n";
		}
	}
}

void zadanie4()
{
	fs::path sciezka("KatalogZadaniowy2");	
	fs::directory_entry ostatni;
	for (const auto& it : fs::directory_iterator(sciezka))
	{
		ostatni = it;
	}
	fs::path sciezka2(ostatni);
	fs::path sciezka3(sciezka2.parent_path().parent_path()/sciezka2.filename());
	fs::copy(sciezka2, sciezka3, fs::copy_options::overwrite_existing);
	fs::resize_file(sciezka3, 1024 * 64);
	std::cout << "\nWielkosc nowego pliku: " << fs::file_size(sciezka3) << " bajtow\n";
	fs::remove(sciezka3);	
}

void zadanie5()
{
	fs::path sciezka("KatalogZadaniowy2");
	int i = 0;
	std::string nazwa;
	
	for (const auto& it : fs::directory_iterator(sciezka))
	{
		fs::path sciezka1 = it.path();
		nazwa = "";
		for (auto &znak: sciezka1.filename().string())
		{
			if (!isdigit(znak)) {
				nazwa += znak;
			}
			else
				break;
		}

		std::string nowaNazwa = nazwa + std::to_string(++i * 2) + "cpy" + sciezka1.extension().string();
		fs::path nowaSciezka = sciezka1.parent_path() / nowaNazwa;
		std::cout << sciezka1 << " " << nowaSciezka << "\n";
		fs::rename(it, nowaSciezka);
	}
}

int main()
{
	zadanie2();
	zadanie3();
	zadanie4();
	zadanie5();
}