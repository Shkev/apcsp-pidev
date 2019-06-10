<!DOCTYPE html>
<html>
  <head>
    <title>Linear System Solver</title>
    <style>
      body {
        background-image: url("koch-snowflake.jpg");
      }
      h4 {
        background-color: "blue"
      }
      input {
        width: 5%;
      }
    </style>
  </head>
  <body>

    <h1 style="color:#B22222;">Enter Coefficients of Variables to solve Linear System</h1>
    <h4 style="color:#F15511;">By: Shayan Azmoodeh and Woocheol Kim</h4>

    <?php
       // define variables and set to empty values
       $arg1 = $arg2 = $arg3 = $arg4 = $arg5 = $arg6 = $arg7 = $arg8 = $arg9 = $arg10 = $arg11 = $arg12 = $output = $retc = "";

       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         $arg2 = test_input($_POST["arg2"]);
         $arg3 = test_input($_POST["arg3"]);
         $arg4 = test_input($_POST["arg4"]);
         $arg5 = test_input($_POST["arg5"]);
         $arg6 = test_input($_POST["arg6"]);
         $arg7 = test_input($_POST["arg7"]);
         $arg8 = test_input($_POST["arg8"]);
         $arg9 = test_input($_POST["arg9"]);
         $arg10 = test_input($_POST["arg10"]);
         $arg11 = test_input($_POST["arg11"]);
         $arg12 = test_input($_POST["arg12"]);
       exec("/usr/lib/cgi-bin/sp1b/php/linSolve " . $arg1 . " " . $arg2 . " " . $arg3 . " " . $arg4 . " " . $arg5 . " " . $arg6 . " " . $arg7 . " " . $arg8 . " " . $arg9 . " " . $arg10 . " " . $arg11 . " " . $arg12, $output, $retc);
       }

       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      
     Equation 1:  <input type="text" name="arg1" value="0"><i>x<sub>1</sub></i> <input type="text" name="arg2" value="0"><i>x<sub>2</sub></i> <input type="text" name="arg3" value="0"><i>x<sub>3</sub></i>&nbsp  =&nbsp  <input type="text" name="arg4" value="0">
      <br><br>Equation 2:   <input type="text" name="arg5" value="0"><i>x<sub>1</sub></i> <input type="text" name="arg6" value="0"><i>x<sub>2</sub></i> <input type="text" name="arg7" value="0"><i>x<sub>3</sub></i>&nbsp=  &nbsp<input type="text" name="arg8" value="0">
      <br><br>Equation 3:  <input type="text" name="arg9" value="0"><i>x<sub>1</sub></i> <input type="text" name="arg10" value="0"><i>x<sub>2</sub></i \> <input type="text" name="arg11" Value="0"><i>x<sub>3</sub></i>&nbsp  =&nbsp  <input type="text" name="arg12" value="0">
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
       if (is_numeric($retc)) {
           echo "<h2>Program Output (an array):</h2>";
           foreach ($output as $line) {
           echo $line;
           echo "<br>";
         }

         echo "<h2>Program Return Code:</h2>";
         echo $retc;
       }
    ?>

  </body>
</html>
