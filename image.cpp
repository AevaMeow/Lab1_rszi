#include <iostream>
#include <vector>
using namespace std;

// 2
class Image {
    public:
        string filename;
        Image(string fname) : filename(fname) {}
    };
    
class ImageProcessor {
    public:
        virtual void Process(Image& image) = 0;  // Чисто виртуальная функция
    };
    
class ImSave : public ImageProcessor {
    public:
        void Process(Image& image) override {
            cout << "Сохраняем картинку... " << endl;
        }
    };
    
class ImResize : public ImageProcessor {
    public:
        void Process(Image& image) override {
            cout << "Меняем размер картинки на 800x600..." << endl;
        }
    };
    
class ImColorInv : public ImageProcessor {
    public:
        void Process(Image& image) override {
            cout << "Меняем цвета на картинке... " << endl;
        }
    };
    
class ImDelDuplicates {
        public:
            int DeleteDuplicates(vector<Image>& images) {
                cout << "Удаляем дубликаты картинок..." << endl;
                return 0;
            }
        };


class ImDownload { //загрузка битового массива с изображением с помощью HTTP запроса
public:
    unsigned char* Download(const string& imageUrl) {
        cout << "Скачиваем изображение с сайта: " << imageUrl << endl;
        return nullptr; 
    }
};

class Account {
public:
    string username;
    string profilePictureUrl;  // "Ссылка" на картинку профиля
    
    Account(string uname) : username(uname), profilePictureUrl("") {}
    
    void SetProfilePicture(const string& imageUrl) {
        profilePictureUrl = imageUrl;
    }

};

class SetImageAsAccountPicture {
    public:
        void SetProfilePictureForAccount(Account& account, const Image& image) {
            cout << "Устанавливаем картинку " << image.filename << " как картинку профиля для пользователя " << account.username << endl;
            string profilePictureUrl = "http://example.com/" + image.filename;  // URL изображения
            account.SetProfilePicture(profilePictureUrl);
            cout << "Пользователь " << account.username << " установил картинку профиля " << endl;
        }
    };

int main() {
// 2
    Image img("kartink.jpg");
    vector<Image> images = {Image("kartink.jpg"), Image("photo.png"), Image("kartink.jpg"), Image("photo2.png")};

    ImSave saveProcessor;
    ImResize resizeProcessor;
    ImColorInv colorInvProcessor;

    saveProcessor.Process(img);
    resizeProcessor.Process(img);
    colorInvProcessor.Process(img);

    ImDelDuplicates delDup;
    delDup.DeleteDuplicates(images);

    ImDownload downloader;
    downloader.Download("http://example.com/kartink.jpg");
    
    Account user1("Аeva");
    SetImageAsAccountPicture profileSetter;
    profileSetter.SetProfilePictureForAccount(user1, img);
    cout << "-----------------------\n";
    return 0;

}