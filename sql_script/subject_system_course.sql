create table course
(
    cno   varchar(50) not null comment '课程号'
        primary key,
    cname varchar(50) not null comment '课程名',
    tno   varchar(50) not null comment '教师号'
);

INSERT INTO subject_system.course (cno, cname, tno) VALUES ('c1001', 'Linux', 't1001');
INSERT INTO subject_system.course (cno, cname, tno) VALUES ('c1002', 'web', 't1001');
INSERT INTO subject_system.course (cno, cname, tno) VALUES ('c1003', 'C语言', 't1001');
INSERT INTO subject_system.course (cno, cname, tno) VALUES ('c1004', 'C++', 't1002');
INSERT INTO subject_system.course (cno, cname, tno) VALUES ('c1005', 'Java', 't1002');