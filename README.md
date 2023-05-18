# 🧪 Thực nghiệm đo chiều cao cây AVL và cây Đỏ-Đen

## 🔴 Mô tả
Repository này chứa mã nguồn và dữ liệu cho thực nghiệm đo chiều cao của **cây AVL** và **cây Đỏ-Đen** qua 10 bộ dữ liệu ngẫu nhiên (mỗi bộ khoảng 10<sup>6</sup> giá trị).

## 🟠 Cấu trúc Repository
Repository chứa file báo cáo kết quả thực nghiệm `Report.pdf` và ba thư mục chính:

1. **`AVLTree`**: Folder chứa code tạo cây AVL và chiều cao của cây với 10 bộ dữ liệu:
  - `AVLTree.cpp`: Code C++ để tạo 10 cây AVL cho 10 bộ dữ liệu và xuất chiều cao của 10 cây tương ứng. ***Mã nguồn tạo cây AVL và thêm dữ liệu vào cây được lấy từ [Greekforgreeks - Insertion in an AVL Tree](https://www.geeksforgeeks.org/insertion-in-an-avl-tree/)***
  - `AVLHeight.txt`: Tệp văn bản chứa chiều cao của 10 cây AVL cho 10 bộ dữ liệu (mỗi chiều cao trên một dòng).
2. **`RedBlackTree`**: Folder chứa code tạo cây Đỏ-đen và chiều cao của cây với 10 bộ dữ liệu:
  - `RedBlackTree.cpp`: Code C++ để tạo 10 cây Đỏ-đen cho 10 bộ dữ liệu và xuất chiều cao của 10 cây tương ứng. ***Mã nguồn tạo cây Đỏ-đen và thêm dữ liệu vào cây được lấy từ [Greekforgreeks - C Program for Red Black Tree Insertion](https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/)***
  - `RedBlackHeight.txt`: Tệp văn bản chứa chiều cao của 10 cây Đỏ-đen cho 10 bộ dữ liệu (mỗi chiều cao trên một dòng).
3. **`Datasets`**: Folder chứa các bộ dữ liệu và code tạo ra 10 bộ dữ liệu đó:
  - Bao gồm 10 file có tên `dataset1.txt`, `dataset2.txt`, ..., `dataset10.txt`. Mỗi file tương ứng với một bộ dữ liệu ngẫu nhiên chứa 1 số nguyên N là (khoảng 10<sup>6</sup>) là số phần tử, tiếp đến là N số nguyên.
  - **`CreateDatasets.cpp`**: Code để tạo 10 file chứa 10 bộ dữ liệu.
 
## 🟢 Quy trình thực nghiệm

1. Chạy `Datasets/CreateDatasets.cpp` để tạo 10 bộ dữ liệu ngẫu nhiên.
2. Biên dịch và chạy `AVLTree/AVLTree.cpp` để tạo 10 cây AVL cho các bộ dữ liệu và ghi nhận chiều cao của các cây vào `AVLTree/AVLHeight.txt`.
3. Biên dịch và chạy `RedBlackTree/RedBlackTree.cpp` để tạo 10 cây Đỏ-Đen cho các bộ dữ liệu và ghi nhận chiều cao của các cây vào `RedBlackTree/RedBlackHeight.txt`.
4. Phân tích các chiều cao đã ghi nhận, so sánh chiều cao cây và giá trị logN, 1.45logN.
5. Viết báo cáo kết quả thực nghiệm.
