//#include <iostream>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//int trigger;
//
//void seokHoon()
//{
//	while(trigger == 0)
//	{
//		cout << "나석훈 : 정석아 사랑해\n";
//		this_thread::sleep_for(std::chrono::milliseconds(1000));
//	}	
//}
//
//void JeongSeok()
//{
//	while (trigger == 0)
//	{
//		this_thread::sleep_for(std::chrono::milliseconds(500));
//		cout << "오정석 : 석훈아 사랑해\n";
//		this_thread::sleep_for(std::chrono::milliseconds(500));
//	}
//}
//
//int main()
//{
//	trigger = 0;
//	cout << "\n--그들의 사랑이 시작된다...\n\n";
//	thread na(seokHoon);
//	thread oh(JeongSeok);
//	
//	while (trigger==0)
//	{
//		cin >> trigger;
//	}
//
//	na.join();
//	oh.join();
//	cout << "\n--그들의 사랑이 끝났다...\n\n";
//}

//#include <iostream>
//#include <map>
//#include <string>
//#include <chrono>
//#include <thread>
//#include <mutex>
//
//std::map<std::string, std::string> g_pages;
//std::mutex g_pages_mutex;
//
//void save_page(const std::string& url)
//{
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    std::string result = "fake content";
//
//    //std::lock_guard<std::mutex> guard(g_pages_mutex);
//    g_pages_mutex.lock();
//    g_pages[url] = result;
//    g_pages_mutex.unlock();
//}
//
//int main()
//{
//    std::thread t1(save_page, "http://foo");
//    std::thread t2(save_page, "http://bar");
//    t1.join();
//    t2.join();
//
//    for (const auto& pair : g_pages) {
//        std::cout << pair.first << " => " << pair.second << '\n';
//    }
//}