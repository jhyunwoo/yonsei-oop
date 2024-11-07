#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

/**********************/
/*******Problem 2******/
/**********************/
/* ID: 2024148005     */
/* NAME: Jeon Hyunwoo */
/**********************/

class Diary {
public:
    void writeDiary(const std::string& inputFileName);
};

int main(int argc, char* argv[]) {
    Diary myDiary;
    myDiary.writeDiary(argv[1]);
    return 0;
}


void Diary::writeDiary(const std::string& inputFileName) {
    // TODO : Implement this function

    // 입력 받을 파일 이름을 불러옴
    std::ifstream infile(inputFileName);
    // 작성할 파일 이름을 저장할 변수 선언
    std::string fileName;
    // 입력 파일 첫 번째 줄에서 파일 이름을 가져와 저장
    infile >> fileName;

    // 파일이 현재 폴더 안에 존재하는지 확인
    bool isNewFile = !std::filesystem::exists(fileName);

    // 파일이 존재하지 않을 경우
    if(isNewFile)
    {
        // 작성할 파일을 생성
        std::ofstream outfile(fileName);
        // 작성할 데이터를 저장할 변수 선언
        std::string data;
        // break 전까지 반복할 while문
        while(true)
        {
            // 파일에서 읽어올 데이터를 저장할 변수
            std::string line;
            // 파일에서 한 줄을 읽어온 뒤 line 변수에 저장
            std::getline(infile, line);
            // \quit를 입력했을 경우
            if(line == "\\quit")
            {
                // 데이터를 초기화함
                data = "";
            // \save를 입력했을 경우
            }else if(line == "\\save")
            {
                // 파일에 데이터를 작성
                outfile << data;
                // 데이터를 초기화함
                data = "";
            // \esc를 입력했을 경우
            }else if(line == "\\esc")
            {
                // while문을 종료함
                break;
            // 그 외 문장을 입력했을 경우
            }else
            {
                // 데이터에 라인을 저장함
                data += line;
                data += "\n";
            }
        }
        // 파일 작성 종료
        outfile.close();
    // 파일이 존재할 경우
    }else
    {
        // 작성할 파일을 열 ofstream 선언
        std::ofstream file;
        // 데이터를 저장할 변수 선언
        std::string data;

        // open mode를 저장할 변수 선언
        std::string openMode;
        // 입력받은 파일에서 두 번째 줄에 있는 입력 모드를 받아옴
        infile>>openMode;
        // append 모드일 경우
        if(openMode == "\\a")
        {
            // append 모드로 파일을 연다
            file.open(fileName, std::ofstream::app);
        // overwrite 모드일 경우
        }else if(openMode == "\\o")
        {
            // overwite 모드로 파일을 연다
            file.open(fileName, std::ofstream::trunc);
        // 그 외 문자일 경우
        }else
        {
            // 오류
            throw std::runtime_error("Error in opening file");
        }

        // break 전까지 반복하는 while 문
        while(true)
        {
            // 파일에서 읽어올 문장을 저장하는 변수
            std::string line;
            // 파일에서 문장을 읽어와 line 변수에 저장
            std::getline(infile, line);
            // \quit를 입력한 경우
            // \quit를 입력했을 경우
            if(line == "\\quit")
            {
                // 데이터를 초기화함
                data = "";
                // \save를 입력했을 경우
            }else if(line == "\\save")
            {
                // 파일에 데이터를 작성
                file << data;
                // 데이터를 초기화함
                data = "";
                // \esc를 입력했을 경우
            }else if(line == "\\esc")
            {
                // while문을 종료함
                break;
                // 그 외 문장을 입력했을 경우
            }else
            {
                // 데이터에 라인을 저장함
                data += line;
                data += "\n";
            }
        }
        // 파일 작성 종료
        file.close();
    }
    // 파일 읽기 종료
    infile.close();
}