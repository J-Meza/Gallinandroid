package com.example.gallinandroid;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import de.nitri.gauge.Gauge;

public class MainActivity extends AppCompatActivity {
Button btnFill;
//http://192.168.137.99:80/CMD+10
    String Baseurl="http://♦:80/CMD+10";
    String url;
    WebView web;
    EditText edtIp;
    Gauge gauge;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btnFill=findViewById(R.id.bntFill);
        web=(WebView) findViewById(R.id.webV);
        web.setWebViewClient(new MyWebClient());
        WebSettings settings=web.getSettings();
        settings.setJavaScriptEnabled(true);
        url="http://192.168.137.99:80/CMD+10";
        edtIp=findViewById(R.id.edtIp);
        edtIp.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                url=Baseurl.replace("♦",s);
                //Toast.makeText(getApplicationContext(),url, Toast.LENGTH_SHORT).show();

            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });
    }
    public void onClickFill(View v) {

        web.loadUrl(url);
        Toast.makeText(this,"Comenzando a llenar", Toast.LENGTH_SHORT).show();
    }

    private class MyWebClient extends WebViewClient {

        @Override
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
            view.loadUrl(url);
            return true;
        }
    }
}
