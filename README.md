## Project Overview🔮
The project involved analyzing a dataset that tracked the frequency of grocery items purchased at Corner Grocer. 
This analysis helps users identify which items are most popular, providing valuable information for inventory management. 
The program also displays the purchase frequency of specific items or all items in a histogram format.

<img width="241" alt="Screenshot 2025-04-20 at 7 31 28 PM" src="https://github.com/user-attachments/assets/1ab4bcf0-e587-469a-9214-87bd25a564f2" />

## How to enhance the code🔨
To enhance the project, I think using pointers could facilitate larger datasets for Corner Grocer. 
Implementing pointers allows for dynamic memory allocation, enabling the addition of more items without needing to set a 
fixed-size array. One practical approach would be to introduce a class to represent each item and store pointers to these 
item objects in a map. This would allow for better memory management, promote object-oriented design, and make it easier 
to expand the project in the future.

## Do particularly well
I believe I effectively validated user input by considering potential incorrect entries and providing specific error 
messages to guide users clearly. I implemented try-catch blocks to handle unexpected errors, ensuring the program could 
manage edge cases that I might not have anticipated.

## Challenge🎯
I found the getValidateChoice function to be the most challenging aspect of the project. I struggled to organize the 
try-catch exception handling effectively and considered whether it was necessary for the project. Ultimately, I decided 
to implement it as an additional layer of protection to prevent the program from crashing due to unforeseen edge cases. 
This implementation also provides users with clear guidance on the expected input. I used resources like zyBooks and 
cppreference.com, which were immensely helpful in overcoming these difficulties. 

## Transferable Skills🚀
I believe that the class-based approach and maintaining clear well-structured code are crucial and widely implemented in
many projects. It is highly transferable for use in future projects. This approach is beneficial because it allows for 
easier data manipulation, better organization, and improved scalability of the code.

## Ways to make this program maintainable, readable, and adaptable🧰🪛⚙️
I separated the main page from other functions to clarify the flow of the project. I aimed to use clear and simple naming
conventions to enhance readability. For the sake of extensibility and maintainability, I defined variables that allow 
future changes to be centralized. For example, the global variable "sentinel" can be easily modified if new features are 
added, reducing duplication and making the code more adaptable.
