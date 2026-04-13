// ---------------------------------------------------------
// Tên dự án: Hệ thống giám sát nhiệt độ LM35
// Tệp tin:   LM35_TempReader.ino
// Chức năng: Đọc nhiệt độ 2 kênh (A0, A1) và xuất định dạng CSV
// ---------------------------------------------------------

const int LM35_PIN_1 = A0; // Cảm biến 1 nối với A0
const int LM35_PIN_2 = A1; // Cảm biến 2 nối với A1

void setup() {
  Serial.begin(9600); 
  // In dòng tiêu đề (Header) cho file CSV
  Serial.println("Temp1,Temp2");
}

void loop() {
  // Bước 1: Đọc giá trị Analog từ 2 kênh
  int adc1 = analogRead(LM35_PIN_1);
  int adc2 = analogRead(LM35_PIN_2);

  // Bước 2: Chuyển đổi sang độ C (sử dụng công thức đã tối ưu)
  float temp1 = (adc1 * 500.0) / 1023.0;
  float temp2 = (adc2 * 500.0) / 1023.0;

  // Bước 3: Gửi dữ liệu theo chuẩn CSV (Giá trị 1, Giá trị 2)
  Serial.print(temp1);
  Serial.print(","); // Chèn dấu phẩy ngăn cách
  Serial.println(temp2); // println ở giá trị cuối để tự động xuống dòng

  // Tạm dừng 1 giây
  delay(1000);
}