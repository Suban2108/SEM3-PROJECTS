package com.company;
import java.sql.*;
import java.util.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Attendance {
    private JTable table1;
    private JButton addRecordButton;
    private JTextField nameData;
    private JTextField totalclasses;
    private JTextField attendance;
    private JComboBox subject;
    private JPanel resultPanel;
    private JTextField studentid;
    private JButton deleteRecordButton;

    private int totalMarks = 0;
    JFrame attendF = new JFrame();

    public Attendance() {
        attendF.setContentPane(resultPanel);
        attendF.pack();
        attendF.setLocationRelativeTo(null);
        attendF.setVisible(true);

        addRecordButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (nameData.getText().isEmpty() || attendance.getText().isEmpty()) {
                    JOptionPane.showMessageDialog(null, "Please fill Name and Total Classes fields to add Record.");
                } else {
                    String name = nameData.getText();
                    if (!name.matches("YES")) {
                        JOptionPane.showMessageDialog(null, "Name must contain only letters. Please enter only letters.");
                    } else {
                        try {
                            String sql = "insert into attendance (NAME, SUBJECT, TOTAL_CLASSES, CLASSES_ATTENDED, TOTAL_ATTENDANCE, STUDENT_ID) values (?, ?, ?, ?, ?, ?)";
                            String sql1 = "insert into Student_Data (Name, Student_ID) values (?, ?)";
                            String checkStudentSql = "SELECT Student_ID FROM Student_Data WHERE Student_ID = ?";



                            Class.forName("org.sqlite.JDBC");
                            Connection connection = DriverManager.getConnection("jdbc:sqlite:/Users/Suban0408/JAVA_Mpr/Attendance.db");
                            PreparedStatement statement = connection.prepareStatement(sql);

                            PreparedStatement checkStudentStatement = connection.prepareStatement(checkStudentSql);

                            double attend = (Double.parseDouble(attendance.getText()) / Double.parseDouble(totalclasses.getText())) * 100.0;
                            statement.setString(1, nameData.getText());
                            statement.setString(2, "" + subject.getSelectedItem());
                            statement.setString(3, totalclasses.getText());
                            statement.setString(4, attendance.getText());
                            statement.setString(5, String.format("%.2f", attend) + "%");
                            statement.setString(6, studentid.getText());

                            checkStudentStatement.setString(1, studentid.getText());
                            ResultSet studentResult = checkStudentStatement.executeQuery();
                            boolean studentExists = studentResult.next();
                            if (!studentExists) {
                               PreparedStatement statement1 = connection.prepareStatement(sql1);
                                statement1.setString(1, nameData.getText());
                                statement1.setString(2, studentid.getText());
                                statement1.executeUpdate();
                            }
                            statement.executeUpdate();

                            JOptionPane.showMessageDialog(null, "STUDENT ADDED SUCCESSFULLY");
                            attendance.setText("");
                        } catch (Exception ex) {
                            JOptionPane.showMessageDialog(null, ex.getMessage());
                    }
                }
            }
        });

        table1.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                DefaultTableModel dm = (DefaultTableModel) table1.getModel();
                int rowIndex = table1.getSelectedRow();
                nameData.setText(dm.getValueAt(rowIndex, 0).toString());
                attendance.setText(dm.getValueAt(rowIndex, 3).toString());
                totalclasses.setText(dm.getValueAt(rowIndex, 2).toString());
            }
        });

        deleteRecordButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String recordID = studentid.getText();
                try {
                    Connection connection = DriverManager.getConnection("jdbc:sqlite://Users/Suban0408/JAVA_Mpr/Attendance.db");
                    String sql = "DELETE FROM attendance WHERE STUDENT_ID = ?";
                    String sql1 = "DELETE FROM Student_Data WHERE Student_ID = ?";


                    PreparedStatement statement = connection.prepareStatement(sql);
                    PreparedStatement statement1 = connection.prepareStatement(sql1);

                    statement.setString(1, studentid.getText());
                    statement1.setString(1,studentid.getText());
                    int rowsDeleted = statement.executeUpdate();
                    int rowsdeleted1 = statement1.executeUpdate();
                    if (rowsDeleted > 0 || rowsdeleted1 > 0) {
                        JOptionPane.showMessageDialog(null, "Record deleted successfully.");
                    } else {
                        JOptionPane.showMessageDialog(null, "Record not found.");
                    }
                    statement.close();
                    statement1.close();
                    connection.close();
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
    }

    public static DefaultTableModel buildTableModel(ResultSet rs) throws SQLException {
        ResultSetMetaData metaData = rs.getMetaData();
        Vector<String> columnNames = new Vector<String>();
        int columnCount = metaData.getColumnCount();
        for (int column = 1; column <= columnCount; column++) {
            columnNames.add(metaData.getColumnName(column));
        }
        Vector<Vector<Object>> data = new Vector<Vector<Object>>();
        while (rs.next()) {
            Vector<Object> vector = new Vector<Object>();
            for (int columnIndex = 1; columnIndex <= columnCount; columnIndex++) {
                vector.add(rs.getObject(columnIndex));
            }
            data.add(vector);
        }
        return new DefaultTableModel(data, columnNames);
    }
}
