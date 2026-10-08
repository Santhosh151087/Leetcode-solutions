SELECT * FROM Users
WHERE mail REGEXP  '^[a-zA-Z][0-9a-zA-Z_.-]*@leetcode[.]com$' and mail like BINARY '%@leetcode.com';
