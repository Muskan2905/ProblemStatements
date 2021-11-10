//Validate a email address
//email address as a parameter
//format : user_name@domain_name : split()
//user_name and domain_name should start 
//with lower case letter : Ascii table
//then letters,digits,hyphens,dots,underscore
//domain_name should end with .org, .in, .com : endsWith()
//hanna@my_school3.edu.org
//h.Al_Zadjali4.50@computing.org

function validate_email(emailAddress){
let len = emailAddress.length;
let count = 0;
let flag = 0;
for(let i =0;i<len;i++){
    if(emailAddress[i] === "@"){
        count ++;
    }
}
if(count == 1){
let splittedEmail = emailAddress.split("@");
if(splittedEmail[0].length != 0 && splittedEmail[1].length != 0){
 if(((/[a-zA-Z]/).test(splittedEmail[0][0]))&&((/[a-zA-Z]/).test(splittedEmail[1][0]))){
 if((splittedEmail[0][0] === splittedEmail[0][0].toLowerCase()) && (splittedEmail[1][0] === splittedEmail[1][0].toLowerCase())){
    check_userName(splittedEmail[0]);
 }
 else{
     console.log("Enter letter in lowercase manner.");
 }
}
else{
    console.log("You can only add first character as letter(lowercase)");
}  
}
else{
    console.log("You need to enter characters before and after '@'.")
}
 function check_userName(user_name){
     for(let i = 1;i<splittedEmail[0].length;i++){
    flag = 0;
    if(((/[a-zA-Z]/).test(splittedEmail[0][i])) || (splittedEmail[0][i] >= "0" && splittedEmail[0][i] <="9") || splittedEmail[0][i] === "-" || splittedEmail[0][i] === "_" || splittedEmail[0][i] === "."){
        flag = 1;
    }
    if(flag == 0){
        console.log("Enter characters either letters,digits,hyphens,underscore or dot");
        break;
    }
  }
  if(flag == 1){
   check_domainName(splittedEmail[1]);
  }
 }
 function check_domainName(domain_name){
    let domain_len = domain_name.length;
    for(let i = 1;i<domain_len;i++){
    flag = 0;
    if(((/[a-zA-Z]/).test(domain_name[i])) || (domain_name[i] >= "0" && domain_name[i] <="9") || domain_name[i] === "-" || domain_name[i] === "_" || domain_name[i] === "."){
        flag = 1;
    }
    if(flag == 0){
        console.log("Enter characters either letters,digits,hyphens,underscore or dot");
        break;
    }
  }
  if(flag == 1){
    if(domain_name.endsWith(".org") || domain_name.endsWith(".in") || domain_name.endsWith(".com")){
        console.log("valid email");        
    }
    else{
        console.log("Your domain should end with either '.org', '.in' or '.com'");
    }
  }
  }
}
else{
    console.log("You can't add more than one '@'.")
}
}

validate_email("h.Al_Zadjali4.50@computing.org");
