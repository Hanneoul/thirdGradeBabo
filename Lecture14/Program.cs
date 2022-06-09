using System.Net;

HttpListener listener = new HttpListener();
listener.Prefixes.Add("http://127.0.0.1:3000/GodDamn/");
listener.Start();
Console.WriteLine("Listening...");
HttpListenerContext context = listener.GetContext();
HttpListenerRequest request = context.Request;
HttpListenerResponse response = context.Response;
Stream body = request.InputStream;
System.Text.Encoding encoding = request.ContentEncoding;
System.IO.StreamReader reader = new System.IO.StreamReader(body, encoding);

string s = reader.ReadToEnd();
string responseString = s;    
System.Console.WriteLine(responseString);
byte[] buffer = System.Text.Encoding.UTF8.GetBytes(responseString);
response.OutputStream.Write(buffer, 0, buffer.Length);
response.OutputStream.Close();
listener.Stop();